from django.shortcuts import render, redirect
from django.http import HttpResponse
from django.forms import inlineformset_factory
from django.contrib.auth.forms import UserCreationForm

from .models import *
from .forms import CreateUserForm  
from product.models import Product

from django.contrib.auth import authenticate, login, logout
from django.contrib import messages

from django.contrib.auth.decorators import login_required


#from .filters import OrderFilter

# Create your views here.
@login_required(login_url='login')
def frontpage(request):
    newest_products = Product.objects.all()[0:8]
    context = {
        'newest_products': newest_products,
    }
    return render(request, 'index.html', context)

def register(request):
    if request.user.is_authenticated:
        return redirect('home')
    else:
        form = CreateUserForm()
        if request.method == 'POST':
            form = CreateUserForm(request.POST)
        if form.is_valid():
            form.save()
            user = form.cleaned_data.get('first_name')
            messages.success(request, 'Account was created for ' + user)
            return redirect('login')

    context ={'form':form}
    return render(request, 'core/register.html', context)
   


def loginPage(request):
    if request.method == 'POST':
        email = request.POST.get('email')
        password = request.POST.get('password')
        
        user = authenticate(request, email=email, password=password)

        if user is not None:
            login(request, user)
            return redirect('home')       
        else:
            messages.info(request, 'Username or Password is incorrect')
            

    return render(request, 'core/login.html')

def logoutUser(request):
    logout(request)
    return redirect('login')


def contactpage(request):
    return render(request, 'core/contact.html')

