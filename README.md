
# Django Project Setup Guide

## Table of Contents
- [Windows 11 Setup](#windows-11-setup)
- [Linux Setup](#linux-setup)
- [Project and App Creation](#project-and-app-creation)
- [Database Operations](#database-operations)
- [Version Control](#version-control)
- [Server Management](#server-management)
- [User Management](#user-management)
- [Miscellaneous Commands](#miscellaneous-commands)

## Windows 11 Setup
```cmd
cmd
mkdir pypro
cd pypro
pip3 install virtualenv
virtualenv -p python3 env
source env/bin/activate
```

For PowerShell:
```powershell
env\scripts\activate
pip install django
```

## Linux Setup
```bash
python3 -m venv env
source env/bin/activate
```

## Project and App Creation
```bash
django-admin startproject mysite
cd mysite
python manage.py startapp polls
python manage.py runserver
python manage.py createsuperuser
```

Sample superuser creation:
```
Username (leave blank to use 'abhinand'): test
Email address: aioont8@gmail.com
Password: test123
```

## Database Operations
```bash
python manage.py makemigrations polls
python manage.py migrate

# Create empty migration
python manage.py makemigrations --empty quantify

# View migration plan
python manage.py migrate --plan
```

### Shell Operations
```bash
python3 manage.py shell
```

Example queries:
```python
from polls.models import Question, Choice
Question.objects.all()
q = Question.objects.get(pk=1)
q.choice_set.create(choice_text="bob", votes=0)
q.save()
exit()
```

## Version Control
```bash
git init
git add <folder1> <folder2> <etc.>
git commit -m "Your message about the commit"
git remote add origin https://github.com/yourUsername/yourRepository.git
git push -u origin master
git push origin master

# Update submodules
git submodule update --init --recursive

# Remove directory (Windows)
RMDIR /S dir_name
```

## Server Management
### Hosting Commands
```bash
# Find and replace IP
find ./ -type f -exec sed -i 's/47\.129\.30\.58/54\.179\.55\.8/g' {} +

# System commands
sudo systemctl daemon-reload
sudo systemctl restart gunicorn
sudo systemctl status gunicorn
sudo systemctl restart nginx

# Trial run
gunicorn --workers 3 --bind 0.0.0.0:9091 aisec.wsgi:application --log-level debug

# Continuous run
gunicorn --bind 127.0.0.1:9091 aisec.wsgi
```

### Running Development Server
```bash
python3 manage.py runserver
python3 manage.py runserver 8002
```

### Port Management
```bash
lsof -i :port_num
```

## User Management
```python
from django.contrib.auth import get_user_model

# Get all emails
User = get_user_model()
emails = User.objects.values_list('email', flat=True)
print(list(emails))

# Create or update admin user
admin_user, created = User.objects.get_or_create(email="admin@gmail.com", defaults={
    "first_name": "Admin",
    "last_name": "User",
    "role": "admin",
    "is_staff": True,
    "is_superuser": True
})

admin_user.is_staff = True
admin_user.is_superuser = True
admin_user.role = "admin"
admin_user.set_password("your_secure_password")
admin_user.save()

# Reset password
try:
    admin_user = User.objects.get(email="admin@gmail.com")
    admin_user.set_password("new_secure_password")
    admin_user.save()
    print("Password reset successfully!")
except User.DoesNotExist:
    print("Admin user does not exist!")
```

## Miscellaneous Commands
```bash
# Create requirements.txt
pip freeze > requirements.txt

# URL configuration note:
# Connect urls.py to views.py in /polls
# 1. Link urls.py mysite to new urls.py in polls dir
# 2. Link new urls.py in /polls and views.py
# Add to main urls.py: path('polls/', include('polls.urls'))
```

### Accessing the App
```
http://127.0.0.1:8002/polls
```


# Wireshark filters
```
tcp.analysis
tcp.port==8000
ip.src==
ip.dst==
http or tcp
http.request
http.request.code==200
tcp.flags.syn

Green => Successfully transmitted
Red => packet error problem
Blue => DNS/Other types of query or reponses
Purple => Related to HTTP (Application oriented protocol)
Orange => TCP handshake 
Gray => Conversation protocols 
```


Links and Tips 

https://thispersondoesnotexist.com/

Principle of design : CESTALT : https://youtu.be/FryaH599ec0
Continuation, Closure, Similairity, Proximity, Symmetry 

mention style guidelines when desigining


# For database structure 
`python manage.py dbshell`

> risknox=> \d audits_assignedaudit


AWS Sever Code Apply and Restart

```sudo lsof -i :9091
sudo lsof -i :9091


sudo kill -9 <PID>


sudo systemctl restart gunicorn

or 

sudo systemctl daemon-reload
sudo systemctl restart gunicorn
sudo systemctl restart nginx
sudo systemctl status gunicorn



gunicorn --workers 3 --bind 0.0.0.0:9091 aisec.wsgi:application --log-level debug
gunicorn --bind 127.0.0.1:9091 aisec.wsgi
gunicorn --workers 3 --bind 0.0.0.0:9092 cyber_insurance.wsgi:application --log-level debug  
gunicorn --bind 127.0.0.1:9092 cyber_insurance.wsgi


sudo netstat -tuln | grep 9091

ssh -i "RisknoxDemo.pem" ubuntu@ip or name

cd /etc/nginx/sites-available/

(venv) ubuntu@ip-172-31-24-179:/etc/nginx/sites-available$ ls
default  django

54.179.19.16

(venv) ubuntu@ip-172-31-24-179:/etc/nginx/sites-available$ cat django
server {
    listen 80;
    server_name 18.142.231.238;

    location = /favicon.ico { 
        access_log off; 
        log_not_found off; 
    }

    location /static/ { 
        alias /home/ubuntu/SECAI/staticfiles/; 
        autoindex on; 
    }

    location / {
        include proxy_params;
        proxy_pass http://0.0.0.0:9091;
    }
}

======================================================================================================

(venv) ubuntu@ip-172-31-24-179:/etc/nginx/sites-available$ cat default 
#
server {
	listen 80 default_server;
	listen [::]:80 default_server;



	root /var/www/html;

	index index.html index.htm index.nginx-debian.html;

	server_name _;

	location / {

		proxy_pass http://0.0.0.0:9091;
		try_files $uri $uri/ =404;
	}
	
	location /static/ {
        	alias /home/ubuntu/SECAI/staticfiles/;
    	}	



}


======================================================================================================
sudo nano /etc/systemd/system/gunicorn.service

[Unit]
Description=gunicorn daemon
After=network.target

[Service]
User=ubuntu
Group=www-data
WorkingDirectory=/home/ubuntu/SECAI
Environment="PATH=/home/ubuntu/SECAI/venv/bin"
Environment="PYTHONPATH=/home/ubuntu/SECAI"
ExecStart=/home/ubuntu/SECAI/venv/bin/gunicorn --workers 3 --bind unix:/home/ubuntu/SECAI/aisec.sock aisec.wsgi:application

[Install]
WantedBy=multi-user.target

======================================================================================================

sudo /etc/systemd/system/resolute_compass.service

[Unit]
Description=gunicorn daemon for ResoluteCompass app
After=network.target

[Service]
User=ubuntu
Group=www-data
WorkingDirectory=/home/ubuntu/ResoluteCompass
Environment="PATH=/home/ubuntu/ResoluteCompass/venv/bin"
ExecStart=/home/ubuntu/ResoluteCompass/venv/bin/gunicorn --workers 3 --bind 127.0.0.1:9092 resolute_compass.wsgi:application

[Install]
WantedBy=multi-user.target

======================================================================================================

sudo nano /etc/systemd/system/accord.service

[Unit]
Description=Accord React App
After=network.target

[Service]
Type=simple
User=ubuntu
WorkingDirectory=/path/to/your/accord/build
ExecStart=/usr/bin/serve -s . -l 3000
Restart=on-failure

[Install]
WantedBy=multi-user.target

======================================================================================================

Commands

sudo lsof -i :9091
sudo systemctl daemon-reload
sudo systemctl restart gunicorn
sudo systemctl status gunicorn

 gunicorn --workers 3 --bind 0.0.0.0:9091 aisec.wsgi:application --log-level debug
 gunicorn --bind 127.0.0.1:9091 aisec.wsgi
 
 
====================================================================================================== 
 
sudo systemctl start gunicorn
sudo systemctl enable gunicorn

sudo systemctl start resolute_compass
sudo systemctl enable resolute_compass

sudo systemctl start accord
sudo systemctl enable accord


sudo systemctl status gunicorn
sudo systemctl status resolute_compass
sudo systemctl status accord

======================================================================================================
