def validate_password(password):
    if len(password) < 6:
        return False
    if not any(char.isdigit() for char in password):
        return False
    if not any(char.isupper() for char in password):
        return False
    return True


if __name__ == "__main__":
    password = input("Įveskite slaptažodį: ")
    print("Tinkamas" if validate_password(password) else "Netinkamas")
