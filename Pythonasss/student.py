class Student:
    def __init__(self, name, age, grades=None):
        self.name = name
        self.age = age
        self.grades = grades if grades is not None else []

    def add_grade(self, grade):
        if 0 <= grade <= 10:
            self.grades.append(grade)
        else:
            print("Pažymys turi būti nuo 0 iki 10.")

    def remove_grade(self, grade):
        if grade in self.grades:
            self.grades.remove(grade)
        else:
            print("Toks pažymys nerastas.")

    def get_average(self):
        if not self.grades:
            return 0
        return sum(self.grades) / len(self.grades)

    def has_passed(self):
        return self.get_average() >= 5

    def print_info(self):
        print(f"Vardas: {self.name}")
        print(f"Amžius: {self.age}")
        print(f"Pažymiai: {self.grades}")
        print(f"Vidurkis: {self.get_average():.2f}")
        print("Išlaikyta" if self.has_passed() else "Neišlaikyta")
