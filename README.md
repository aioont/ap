# How to test on win 11
```
cmd
mkdir pypro
cd pypro
pip3 install virtualenv
virtualenv -p python3 env
source env/bin/activate
```

(PS C:\Users\Abhinand\code\pypro\pypro> 'venv\scripts\activate'
venv\scripts\activate)

> pip install django

```
cd ../..
django-admin startproject mysite
cd mysite
python manage.py startapp polls
python manage.py runserver
python manage.py createsuperuser
Username (leave blank to use 'abhinand'): test
Email address: aioont8@gmail.com
Password: test123
```

> python manage.py makemigrations polls

> python manage.py migrate



```
git init
git add <folder1> <folder2> <etc.>
git commit -m "Your message about the commit"
git remote add origin https://github.com/yourUsername/yourRepository.git
git push -u origin master
git push origin master  

RMDIR /S dir_name
```


### ===Linux
python3 -m venv myenv
source myenv/bin/activate

### ===How create project and app

django-admin startproject mysite
python3 manage.py startapp polls

### ===To views table content in terminal
```
❯ python3 manage.py shell
>>> from account.models import User
>>> users = User.objects.all()
>>> users
<QuerySet [<User: admin@gmail.com>, <User: test@gmail.com>]>
```

```
import django
from polls.models import Question,Choice
Question.objects.all()
q = Question.objects.get(pk=1)
q.choice_set.create(choice_text="bob",votes=0)
q.save()
exit()
```

# TO RUN SERVER
> python3 manage.py runserver    

> Adding urls

connect urls.py to views.py in /polls 2-startproject 

1.link urls.py mysite to new urls.py in polls dir

2. link new urls.py in /polls and views.py    >   path('polls/', include('polls.urls')),

# To run
python3 manage.py runserver 8002
http://127.0.0.1:8002/polls

# Port already in use

lsof -i :port num

# How create requiremnts.txt from installed packages

> pip freeze > requirements.txt


