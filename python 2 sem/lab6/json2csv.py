import argparse
import json
import csv
import os
import sys

def main():
    parser = argparse.ArgumentParser(description='Convert JSON to CSV')
    parser.add_argument('json_file', help='Path to the JSON file')
    args = parser.parse_args()


    if not os.path.exists(args.json_file):
        print(f"Ошибка: Файл '{args.json_file}' не найден.", file=sys.stderr)
        sys.exit(1)

    try:
        with open(args.json_file, 'r', encoding='utf-8') as f:
            data = json.load(f)
    except json.JSONDecodeError as e:
        print(f"Ошибка декодирования JSON: {e}", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"Ошибка: {e}", file=sys.stderr)
        sys.exit(1)
    mass=[]
    for entry in data:
        mass.append(entry)

    csv_path = ""
    for entry in mass:
        headers = []
        if data:
            if not isinstance(data[entry][0], dict):
                print("Ошибка: Элементы массива должны быть объектами.", file=sys.stderr)
                sys.exit(1)
            headers = data[entry][0].keys()


        base_name = os.path.splitext(args.json_file)[0]
        csv_path = f"{base_name}.csv"

        try:
            with open(csv_path, 'w', encoding='utf-8', newline='') as f:
                writer = csv.DictWriter(f, fieldnames=headers)
                writer.writeheader()
                for item in data[entry]:
                    if not isinstance(item, dict):
                        print("Пропуск элемента: не является объектом.", file=sys.stderr)
                        continue
                    writer.writerow(item)
        except IOError as e:
            print(f"Ошибка записи CSV: {e}", file=sys.stderr)
            sys.exit(1)

    print(f"Успешно: {args.json_file} -> {csv_path}")

if __name__ == "__main__":
    main()