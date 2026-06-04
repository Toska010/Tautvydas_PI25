from utils import safe_average


def check_grade(g):
    if g >= 5:
        return "Išlaikyta"
    else:
        return "Neišlaikyta"


def print_grades(grades):
    for grade in grades:
        print(f"Pažymys: {grade} -> {check_grade(grade)}")


def print_student_result(student):
    average = safe_average(student.grades)
    print(f"Studentas: {student.name}")
    print(f"Pažymiai: {student.grades}")
    print(f"Vidurkis: {average:.2f}")
    if average >= 5:
        print("Išlaikyta")
    else:
        print("Neišlaikyta")
