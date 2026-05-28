class Suniukas:
    def __init__(self, vardas, amzius):
        self.vardas = vardas
        self.amzius = amzius

    def __str__(self):
        return f"Suniukas {self.vardas}, {self.amzius} metų"

mano_suo = Suniukas("Rikis", 3)
print(mano_suo)

#print(mano_suo)
#print(mano_suo.__dict__)
