def safe_average(numbers):
    if not numbers:
        return 0

    try:
        return sum(numbers) / len(numbers)
    except Exception as error:
        print(f"Klaida skaičiuojant vidurkį: {error}")
        return 0
