
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
```


---

# Git Basics

## Configure Git

```bash
git config --list
git config --global user.name "username"
git config --global user.email "email"
```

Check configured remote repositories:

```bash
git remote -v
```

---

# Branch Merging

## Method 1: Merge using CLI

Compare differences between branches:

```bash
git diff <branch_name>
```

Merge the branch into the current branch:

```bash
git merge <branch_name>
```

Example:

```bash
git checkout main
git merge master
```

---

## Method 2: Pull Request (PR)

1. Push your branch to the remote repository.
2. Open the repository on GitHub/GitLab.
3. Create a **Pull Request (PR)**.
4. Review changes.
5. Merge the PR.

---

# Undoing Changes

## Case 1: Staged Changes (Added but Not Committed)

If you used `git add` but haven't committed yet.

Unstage a specific file:

```bash
git reset <file_name>
```

Unstage all files:

```bash
git reset
```

### You Deleted the File and Ran git add . Only
File deleted → git add .

a. Unstage the deletion:
   > git reset HEAD custom_tools.py
b. Restore the file:
   > git restore custom_tools.py

---

## Case 2: Committed Changes (Not Pushed Yet)

If you committed but want to undo the last commit.

```bash
git reset HEAD~1
```

This removes the last commit but **keeps the changes in your working directory**.


### You Deleted the File and Ran git add . + git commit
File deleted
git add .
git commit

a. Method 1 (Recommended)
   Restore file from previous commit:
   > git checkout HEAD~1 -- custom_tools.py
   Then commit again:
   > git add custom_tools.py
   > git commit -m "restore deleted file"
b. Method 2
   If the commit was only the deletion:

   > git reset HEAD~1

---

## Case 3: Reset to a Specific Commit

If you want to go back to a specific commit:

```bash
git reset <commit_hash>
```

---

## Hard Reset (Dangerous)

Reset the repository **and delete all changes after a commit**.

```bash
git reset --hard <commit_hash>
```

⚠️ This will:

* Reset the Git history
* Remove changes from **VS Code / working directory**
* Permanently delete uncommitted work

Use with caution.


### Deleted File Already Pushed to GitHub
a. Find the commit containing the file:
   > git log
b. Restore the file:
   > git checkout <commit_hash> -- custom_tools.py
c. Then commit and push:
   > git add custom_tools.py
   > git commit -m "restore deleted file"
   > git push
---

---

# Notes

* `git diff` → Shows differences between commits/branches.
* `git reset` → Moves HEAD to another commit.
* `git reset --hard` → Completely resets code and history.
* Use Pull Requests for **team collaboration**.



---

# Git Advanced Commands Guide

This document explains some **advanced Git commands** useful for managing commits, fixing mistakes, and maintaining a clean repository history.

---

# 1. Patch Level Commit

Commit specific changes from a file interactively.

```bash
git add -p index.html
```

Git will show each change block and ask:

* `y` → stage the change
* `n` → skip the change

This allows committing **specific portions of a file instead of the entire file**.

---

# 2. Undo Merge / Rebase Conflicts

If a merge or rebase causes conflicts, you can abort it.

### Abort Merge

```bash
git merge --abort
```

### Abort Rebase

```bash
git rebase --abort
```

This restores the repository to the **previous state before the operation started**.

---

# 3. Git Reset

`git reset` moves the current branch pointer to a previous commit.

### Types of Reset

| Mode                | Effect                     |
| ------------------- | -------------------------- |
| `--soft`            | Keeps changes staged       |
| `--mixed` (default) | Keeps changes but unstaged |
| `--hard`            | Deletes all changes        |

---

## 3.1 Mixed Reset (Default)

```bash
git reset --mixed <commit_hash>
```

* Moves HEAD to the specified commit
* Files become **unstaged**
* Changes remain in working directory

If pushed earlier, pushing again may require:

```bash
git push -f
```

---

## 3.2 Soft Reset

```bash
git reset --soft <commit_hash>
```

* Keeps changes staged
* Useful for **modifying commit history**
* Files remain in local repository

---

## 3.3 Hard Reset

```bash
git reset --hard <commit_hash>
```

* Resets repository to a specific commit
* Removes changes from **local repository**
* If force pushed, it removes history from remote as well

⚠ **Dangerous operation** — history can be permanently lost.

---

# 4. Amend Commit

Instead of creating multiple commits, you can modify the previous commit.

```bash
git commit --amend
```

This allows you to:

* Change commit message
* Add forgotten files
* Clean up commit history

Example:

```bash
git add forgotten_file.txt
git commit --amend
```

---

# 5. Cherry Pick

Apply a specific commit from one branch to another.

```bash
git cherry-pick <commit_hash>
```

### Example

Branch 1:

```
feature-1.txt
feature-2.txt
feature-4.txt
```

Branch 2:

```
feature-1.txt
feature-2.txt
feature-3.txt
```

If Branch 2 needs a commit from Branch 1:

```bash
git cherry-pick <commit_hash>
```

Useful when **developers work in parallel and need selected changes without merging entire branches**.

---

# 6. Interactive Rebase

Interactive rebase helps clean commit history.

```bash
git rebase -i <commit_hash>
```

Example:

```
commit 6 (389...)
commit 5 (d40...)
commit 4 (536...)
commit 3
```

Command:

```bash
git rebase -i 536...
```

Git opens an editor to modify commits.

---

## 6.1 Squash Commits

Combine multiple commits into one.

Example:

```
pick 389... commit 6
squash d40... commit 5
```

Result:

```
Merged commit for feature 5 & feature 6
```

Old commits are removed after pushing.

---

## 6.2 Drop Commit

Remove a commit completely.

```bash
git rebase -i
```

Change:

```
pick <commit_hash>
```

to

```
drop <commit_hash>
```

---

````markdown
### c. Bisect

`git bisect` - identify the git commit which introduced the bug in the repository.

```bash
git bisect start
````

Mention good and bad commit.

```bash
grep "BUG!" *.txt
```

Output:

```
feature11.txt: This feature contains a BUG
```

```bash
git bisect bad
```

Output:

```
status: waiting for good commit, bad commit known
```

```bash
git bisect good <commit_hash>
```

Using binary search, the bisect pointer moves to the middle of the bad and good commit.
So let's say the pointer is on commit **9** and the bug is in **11th commit**.
Again run git bisect and mark as good commit.

```bash
git bisect good <9th_commit_hash>
```

Then again:

```bash
grep "BUG!" *.txt
```

This will return the result.

```bash
git bisect bad <13th_commit_id>
```

Then again (pointer on **11**), check whether feature 11 has bug or not.

```bash
grep "BUG!" *.txt
```

```bash
git bisect bad <11th_commit_id>
```

Then again:

```bash
grep "BUG!" *.txt
```

Then **10th commit is good**, which does not return anything.
So we set it as good.

```bash
git bisect good <10th_commit_id>
```

```bash
git bisect log
```

---

### Git Stash

`git stash`

Hold changes for a moment, after pull re-add.

Example branch:

```
test-branch-1
change1.txt
change2.txt
```

Change 1 to stash.

---

#### a. `git stash -u` (untracked file)

File will be stashed including untracked files.

Show stash list:

```bash
git stash list
```

Example output:

```
stash@{0}: identifier
```

Now stash `change2.txt`.

```bash
touch change2.txt
git stash -u
git stash list
```

Then pop:

```bash
git status
```

Output will say **nothing to commit**.

```bash
git stash pop
```

(`change2.txt` is pulled from stash)

Check stash list:

```bash
git stash list
```

Only `stash@{0}` will be there.

```bash
git stash pop
```

(`change1.txt` is pulled from stash)

---

#### b. `git stash` (for tracked file)

```bash
git add change1.txt
git stash
git stash pop
```

When files are in stash list:

* `git stash pop` → **LIFO (Last In First Out)**
* `git stash apply` → popped but still item will remain in stash list

```

## 8.5 Drop Stash

Remove latest stash entry.

```bash
git stash drop
```

---

## 8.6 Show Stash Changes

```bash
git stash show stash@{0}
```

Displays file changes.

---

## 8.7 Clear All Stash

```bash
git stash clear
```

⚠ **Dangerous — cannot recover stash once cleared.**

---




