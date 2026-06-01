import asyncio


async def load_student():
    await asyncio.sleep(1)
    print("Studentas įkeltas (async)")


async def load_all():
    await asyncio.sleep(1)
    print("Visi studentai įkelti (async)")


async def async_main():
    # paleidžiam abi užduotis
    await load_student()
    await load_all()


def run_async_demo():
    asyncio.run(async_main())
