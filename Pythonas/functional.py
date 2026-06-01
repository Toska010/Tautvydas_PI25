from utils import safe_list_sum


def show_functional_demo():
    grades = [4, 7, 9, 10]

    # map – pakelia reikšmes +1
    incremented = list(map(lambda x: x + 1, grades))

    # pakeista lambda sąlyga: >= 7
    filtered = list(filter(lambda x: x >= 7, incremented))

    print("Pradiniai pažymiai:", grades)
    print("Padidinti pažymiai (+1):", incremented)
    print("Atrinkti (>= 7):", filtered)
    print("Suma (safe_list_sum):", safe_list_sum(filtered))
