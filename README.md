# Project_Igloo

A C++ desktop GUI app built with **wxWidgets** and **libpqxx** to manage user login data in a PostgreSQL database.

---

## 🛠 Requirements

Before doing anything, make sure the following are installed on your machine:

- **Visual Studio 2022** (with the "Desktop development with C++" workload)
- **Visual Studio Code**
- **Git**
- **vcpkg** (installed at `C:\VS\vcpkg`)
- PostgreSQL installed locally (if you're testing the database functionality)

---

## 📦 Setup (First Time on a New Machine)

```bash
git clone https://github.com/yourusername/Project_Igloo_V2.git
cd Project_Igloo_V2
vcpkg install
code .


cd C:\VS\Project_Igloo_V2
cl /std:c++17 /EHsc /I C:\VS\vcpkg\installed\x64-windows\include *.cpp /link /LIBPATH:C:\VS\vcpkg\installed\x64-windows\lib pqxx.lib libpq.lib wxmsw32u_core.lib wxbase32u.lib comctl32.lib rpcrt4.lib
