from student_info import print_student_info
from student_logic import check_grade
from student_data import print_students
from file_manager import write_data, read_data
from functional import show_functional_demo
from api_students import fetch_users
from async_students import run_async_demo
from test_student import run_tests
from auth import check_password

print("=== Naujas MOODLE ===")
print("Sistema paleista sėkmingai!")
print("Duomenys bus apdorojami...")

print_student_info()

print("\n--- Studentų sąrašas iš student_data.py ---")
print_students()

print("\n--- Pažymio tikrinimo pavyzdžiai ---")
check_grade(8)
check_grade(4)

print("\n--- Utils / functional pavyzdžiai ---")
show_functional_demo()

print("\n--- Failo rašymas ir skaitymas ---")
write_data()
read_data()

print("\n--- API vartotojų gavimas ---")
fetch_users()

print("\n--- Async pavyzdys ---")
run_async_demo()

print("\n--- Testai ---")
run_tests()

print("\n--- Slaptažodžio tikrinimas ---")
for pwd in ["abc", "abc123", "Abc123", "LabaiStiprus1"]:
    print(f"'{pwd}' ->", "GERAS" if check_password(pwd) else "BLOGAS")
