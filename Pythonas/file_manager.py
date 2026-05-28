def write_data():
    with open("data.txt", "w", encoding="utf-8") as f:
        f.write("Jonas,8\n")
        f.write("Aiste,10\n")
        f.write("Mantas,6\n")  # papildoma eilutė


def read_data():
    with open("data.txt", "r", encoding="utf-8") as f:
        content = f.read()
    print("Failo turinys:")
    print(content)
