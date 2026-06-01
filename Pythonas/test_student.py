from student import Student


def run_tests():
    print("Testas 1: Student('Jonas', [8, 9, 10])")
    s = Student("Jonas", [8, 9, 10])
    avg = s.get_average()
    if avg == 9:
        print("OK")
    else:
        print("Klaida, gautas vidurkis:", avg)

    print("Testas 2: Student('Aiste', [10, 10])")
    s2 = Student("Aiste", [10, 10])
    avg2 = s2.get_average()
    if avg2 == 10:
        print("OK")
    else:
        print("Klaida, gautas vidurkis:", avg2)
