def check_password(pwd: str) -> bool:
    # ilgis ≥ 6
    if len(pwd) < 6:
        return False

    # bent vienas skaičius
    if not any(c.isdigit() for c in pwd):
        return False

    # bent viena didžioji raidė
    if not any(c.isupper() for c in pwd):
        return False

    return True
