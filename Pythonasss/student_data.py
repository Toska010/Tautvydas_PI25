from student import Student

students = [
    Student("Jonas", 20, [8, 7, 6]),
    Student("Ona", 21, [10, 9, 8]),
    Student("Tomas", 19, [4, 5, 6]),
]

average_bonus = 1.5

for student in students:
    print(student.name, student.age, student.grades)

print("Float reikšmė:", average_bonus)
