def write_students_file(filename="students.txt"):
    with open(filename, "w", encoding="utf-8") as file:
        file.write("Jonas,20,[8, 7, 6]
")
        file.write("Ona,21,[10, 9, 8]
")
        file.write("Tomas,19,[4, 5, 6]
")


def read_students_file(filename="students.txt"):
    with open(filename, "r", encoding="utf-8") as file:
        data = file.read()
        print(data)
        return data


if __name__ == "__main__":
    write_students_file()
    read_students_file()
