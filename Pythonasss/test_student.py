from student import Student


def run_tests():
    student1 = Student("Jonas", 20, [8, 8, 8])
    if student1.get_average() == 8:
        print("OK")
    else:
        print("Klaida")

    student2 = Student("Tomas", 19, [3, 4, 5])
    if student2.has_passed() is False:
        print("OK")
    else:
        print("Klaida")


if __name__ == "__main__":
    run_tests()
