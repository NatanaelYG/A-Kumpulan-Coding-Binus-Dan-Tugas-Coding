@echo off
d:
cd "Computer Physics\Software"
call environments\computational_physics\Scripts\activate.bat
cd ppe_webapp_py3_4_4_0/simulator_interface
start http://127.0.0.1:8000/
python manage.py runserver
echo -e "\n"
pause