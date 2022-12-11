from django.urls import path
from . import views

app_name = 'core'


urlpatterns = [
    path('', views.frontpage, name="home"),
    path('register/', views.register, name="register"),
    path('login/', views.loginPage, name="login"),
    path('logout/', views.logoutUser, name="logoutUser"),
    path('contact/', views.contactpage, name="contact"),
]
