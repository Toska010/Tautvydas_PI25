class Student:
    def __init__(self, name, grades):
        self.name = name
        self.grades = grades  # sąrašas pažymių

    def get_average(self):
        if not self.grades:
            return 0
        return sum(self.grades) / len(self.grades)

    def print_info(self):
        print(f"Vardas: {self.name}, Pažymiai: {self.grades}, Vidurkis: {self.get_average():.2f}")
