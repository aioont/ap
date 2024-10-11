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
