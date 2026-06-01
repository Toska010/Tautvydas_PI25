class Studentas:
    def __init__(self, vardas, ivertinimas, vidurkis):
        self.vardas = vardas
        self.ivertinimas = ivertinimas
        self.vidurkis = vidurkis
    def __str__(self) -> str:
        return f"Studentas: {self.vardas}, įvertinimai: {self.ivertinimas}, vidurkis: {self.vidurkis}"
def print_students():
    Jonas = Studentas("Jonas", 8, 7.5)
    print(Jonas)
    Aiste = Studentas("Aiste", 10, 9.3)
    print(Aiste)
    Mantas = Studentas("Mantas", 6, 6.8)
    print(Mantas)

#"Studentas": "Jonas", "įvertinimas": 8, "vidurkis": 7.5
#"Studentas": "Aiste", "įvertinimas": 10, "vidurkis": 9.3
#"Studentas": "Mantas", "įvertinimas": 6, "vidurkis": 6.8