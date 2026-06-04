from student import Student
from student_data import students
from student_logic import print_student_result
from functional import raise_values

SYSTEM_NAME = "Studentų valdymo sistema v2"


def find_student(name):
    for student in students:
        if student.name.lower() == name.lower():
            return student
    return None


def add_student():
    name = input("Įveskite studento vardą: ")
    age = int(input("Įveskite studento amžių: "))
    students.append(Student(name, age, []))
    print("Studentas pridėtas.")


def remove_student():
    name = input("Įveskite studento vardą šalinimui: ")
    student = find_student(name)
    if student:
        students.remove(student)
        print("Studentas pašalintas.")
    else:
        print("Studentas nerastas.")


def add_grade():
    name = input("Studento vardas: ")
    student = find_student(name)
    if student:
        grade = int(input("Įveskite pažymį: "))
        student.add_grade(grade)
        print("Pažymys pridėtas.")
    else:
        print("Studentas nerastas.")


def remove_grade():
    name = input("Studento vardas: ")
    student = find_student(name)
    if student:
        grade = int(input("Kokį pažymį pašalinti: "))
        student.remove_grade(grade)
    else:
        print("Studentas nerastas.")


def show_all_grades():
    for student in students:
        print(f"{student.name}: {student.grades}")


def show_one_student_grades():
    name = input("Studento vardas: ")
    student = find_student(name)
    if student:
        print(f"{student.name} pažymiai: {student.grades}")
    else:
        print("Studentas nerastas.")


def show_student_info():
    name = input("Studento vardas: ")
    student = find_student(name)
    if student:
        print_student_result(student)
    else:
        print("Studentas nerastas.")


def raise_student_grades():
    name = input("Studento vardas: ")
    student = find_student(name)
    if student:
        student.grades = raise_values(student.grades)
        print("Pažymiai pakelti, bet ne daugiau kaip iki 10.")
    else:
        print("Studentas nerastas.")


def menu():
    while True:
        print("" + "=" * 40)
        print(SYSTEM_NAME)
        print("Pasirinkite veiksmą")
        print("Valdykite studentus ir jų pažymius")
        print("1 - Pridėti studentą")
        print("2 - Pašalinti studentą")
        print("3 - Pridėti pažymį")
        print("4 - Pašalinti pažymį")
        print("5 - Peržiūrėti visų studentų pažymius")
        print("6 - Peržiūrėti konkretaus studento pažymius")
        print("7 - Parodyti studento informaciją ir ar išlaikė")
        print("8 - Pakelti studento pažymius +1")
        print("0 - Išeiti")

        choice = input("Jūsų pasirinkimas: ")

        if choice == "1":
            add_student()
        elif choice == "2":
            remove_student()
        elif choice == "3":
            add_grade()
        elif choice == "4":
            remove_grade()
        elif choice == "5":
            show_all_grades()
        elif choice == "6":
            show_one_student_grades()
        elif choice == "7":
            show_student_info()
        elif choice == "8":
            raise_student_grades()
        elif choice == "0":
            print("Programa baigta.")
            break
        else:
            print("Neteisingas pasirinkimas.")


if __name__ == "__main__":
    menu()
