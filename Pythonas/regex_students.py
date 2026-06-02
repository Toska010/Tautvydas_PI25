import re


def extract_name(line: str):
    # Pvz.: "Jonas 8", "PrekeX 12.99"
    # Ištraukiam tik raidinę dalį (vardą/pavadinimą)
    match = re.findall(r"[A-Za-zĄČĘĖĮŠŲŪŽąčęėįšųūž]+", line)
    return match[0] if match else None


def has_number(line: str) -> bool:
    # Patikrinam, ar eilutėje yra bent vienas skaičius
    return bool(re.search(r"\d", line))


def demo_regex():
    lines = ["Jonas 8", "PrekeX 12.99", "BeSkaiciaus"]
    for l in lines:
        print(f"Eilutė: {l}")
        print("  Turi skaičių?:", has_number(l))
        print("  Vardas/pavadinimas:", extract_name(l))
