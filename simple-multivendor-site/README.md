# Digital Product E-commerce
<h3>
  <li>Django Simple Multi-Vendor Website with Payment</li>
 </h3>
<p>Digital Product E-commerce (DPE) is academic project done by aioont. It is a e-commerce platform to buy and sell digital products.

This is a simple MultiVendor e-commerce website built with Django (Python) and Stripe is added as payment processor.

In this website, Vendors (Stores) can register and add their products.

And Users can visit the product and order by paying with Debit/Credit Card (Stripe is Used).

Then Vendor gets the email notification about the order and should deliver the product to the customer based on the address details.
</p>


And if you like this project then ADD a STAR ⭐️  to this project 👆
<h3> 
<li>Features of this Project</li>
</h3>

### A. Admin Users Can
1. Manage Category (Add, Update, Filter and Delete)
2. Manage Products (Add, Update, Filter and Delete)
3. Manage Users (Update, Filter and Delete)
4. Manage Orders (View and Process)

### B. Vendors Can
1. Add Products
2. Update Profile
3. Gets Notification When an Order is made by Users
4. Get Orders and Manage Them


### C.  Users Can Can
1. Add to Cart
2. Pay with Debit/Credit Card and Order
3. While Checkout, User should give the address to deliver
4. Get Email Notification about the confirmation of the order

<h3> 
<li> ## How to Install and Run this project? </li>
</h3> 

### Pre-Requisites:
1. Install Git Version Control
[ https://git-scm.com/ ]

2. Install Python Latest Version
[ https://www.python.org/downloads/ ]

3. Install Pip (Package Manager)
[ https://pip.pypa.io/en/stable/installing/ ]

*Alternative to Pip is Homebrew*

### Installation
**1. Create a Folder where you want to save the project**

**2. Create a Virtual Environment and Activate**

Install Virtual Environment First
```
$  pip install virtualenv
```

Create Virtual Environment

For Windows
```
$  python -m venv venv
```
For Mac
```
$  python3 -m venv venv
```

Activate Virtual Environment

For Windows
```
$  source venv/scripts/activate
```

For Mac
```
$  source venv/bin/activate
```

**3. Clone this project**
```
$  git clone https://github.com/vijaythapa333/simple-multivendor-site.git
```

Then, Enter the project
```
$  cd simple-multivendor-site
```

**4. Install Requirements from 'requirements.txt'**
```python
$  pip install -r requirements.txt
```

**5. Add the hosts**

- Got to settings.py file 
- Then, On allowed hosts, Add [‘*’]. 
```python
ALLOWED_HOSTS = ['*']
```
*No need to change on Mac.*


**6. Now Run Server**

Command for PC:
```python
$ python manage.py runserver
```

Command for Mac:
```python
$ python3 manage.py runserver
```

**7. Login Credentials**

Create Super User (Admin)

Command for PC:
```
$  python manage.py createsuperuser
```

Command for MAC:
```
$  python3 manage.py createsuperuser
```
Then Add Email, Username and Password
</ol>


Reference : https://github.com/vijaythapa333/simple-multivendor-site
