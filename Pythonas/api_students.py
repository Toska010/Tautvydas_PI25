import requests


def fetch_users():
    url = "https://jsonplaceholder.typicode.com/users"
    try:
        r = requests.get(url, timeout=5)
    except Exception as e:
        print("Klaida jungiantis prie API:", e)
        return

    if r.status_code != 200:
        print("Klaida gaunant duomenis, status_code:", r.status_code)
        return

    users = r.json()

    for u in users:
        # išvedam tik name ir email
        print("Name:", u.get("name"), "| Email:", u.get("email"))
