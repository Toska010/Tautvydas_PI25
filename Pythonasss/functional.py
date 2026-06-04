def raise_values(values):
    new_values = list(map(lambda x: min(x + 1, 10), values))
    print("Naujas sąrašas:", new_values)
    return new_values


def filter_good_values(values):
    return list(filter(lambda x: x >= 7, values))


if __name__ == "__main__":
    grades = [4, 6, 9, 10]
    raise_values(grades)
    print("Atrinkti pažymiai:", filter_good_values(grades))
