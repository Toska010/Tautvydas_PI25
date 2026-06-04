import re


def line_has_number(text):
    return bool(re.search(r"\d", text))


def extract_name(text):
    match = re.search(r"^([A-Za-zĄČĘĖĮŠŲŪŽąčęėįšųūž]+)", text)
    if match:
        return match.group(1)
    return ""


if __name__ == "__main__":
    line = "Jonas pažymys: 8 kaina: 12.5"
    print("Ar yra skaičių:", line_has_number(line))
    print("Tik vardas:", extract_name(line))
