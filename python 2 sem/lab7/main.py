import json
from jsonschema import validate, ValidationError

#1 задание
def validate_json(json_file, schema_file):
    with open(json_file, 'r') as f:
        data = json.load(f)

    with open(schema_file, 'r') as f:
        schema = json.load(f)

    try:
        validate(instance=data, schema=schema)
        print("Валидация успешна!")
    except ValidationError as e:
        print("Ошибка валидации:")
        print(e.message)


# Валидация исходного файла
print("Проверка исходного файла:\n")
validate_json('ex_1.json', 'schema_1.json')

# Валидация файла с ошибкой
print("Проверка файла с ошибкой:")
validate_json('ex_1_invalid.json', 'schema_1.json')

#2 задание


# Чтение исходного файла
with open('ex_2.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

# Запись отформатированного JSON
with open('ex_2.json', 'w', encoding='utf-8') as f:
    json.dump(data, f, indent=4, ensure_ascii=False)

with open('ex_2.json', 'r', encoding='utf-8') as f:
    users = json.load(f)

phonebook = {user['name']: user['phoneNumber'] for user in users}

for name, phone in phonebook.items():
    print(f"{name}: {phone}")

#3 задание

with open('ex_3.json', 'r', encoding='utf-8') as f:
    data = json.load(f)


new_invoice = {
    "id": 3,
    "total": 130.00,
    "items": [
        {
            "name": "item 4",
            "quantity": 3,
            "price": 30.00
        },
        {
            "name": "item 5",
            "quantity": 2,
            "price": 20.00
        }
    ]
}

data['invoices'].append(new_invoice)


with open('ex_3_updated.json', 'w', encoding='utf-8') as f:
    json.dump(data, f, indent=4, ensure_ascii=False)

