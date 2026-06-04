import asyncio


async def load_students():
    await asyncio.sleep(1)
    print("Studentai užkrauti")


async def load_grades():
    await asyncio.sleep(1)
    print("Pažymiai užkrauti")


async def main():
    await asyncio.gather(load_students(), load_grades())


if __name__ == "__main__":
    asyncio.run(main())
