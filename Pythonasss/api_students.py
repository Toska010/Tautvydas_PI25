import requests


def get_students_from_api():
    url = "https://jsonplaceholder.typicode.com/users"
    response = requests.get(url, timeout=10)

    if response.status_code == 200:
        data = response.json()
        for item in data:
            print(f"{item['name']} - {item['email']}")
    else:
        print(f"Klaida. status_code: {response.status_code}")


if __name__ == "__main__":
    get_students_from_api()
