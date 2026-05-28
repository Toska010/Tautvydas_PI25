def safe_list_sum(lst):
    # jei sąrašas tuščias – grąžinam 0
    if not lst:
        return 0

    try:
        return sum(lst)
    except Exception as e:
        print("Klaida skaičiuojant sumą:", e)
        return 0
