import csv
import os
import random
from typing import List, Dict, Union


class CSV:
    def __init__(self, filename: str):
        self.filename = filename
        self.data: List[Dict[str, str]] = []
        self.headers: List[str] = []
        self._load_data()

    def _load_data(self) -> None:
        try:
            with open(self.filename, 'r', newline='', encoding='utf-8') as f:
                reader = csv.DictReader(f)
                self.headers = reader.fieldnames or []
                self.data = [row for row in reader]
        except FileNotFoundError:
            raise FileNotFoundError(f"Файл {self.filename} не найден")

    def show(self, mode: str = 'top', n: int = 5, separator: str = ',') -> None:
        if not self.data:
            print("Нет данных для отображения")
            return
        if mode == 'top':
            subset = self.data[:n]
        elif mode == 'bottom':
            subset = self.data[-n:]
        elif mode == 'random':
            subset = random.sample(self.data, min(n, len(self.data)))
        else:
            raise ValueError("Недопустимый режим. Допустимые значения: top, bottom, random")

        header = separator.join(self.headers)
        print(f"\n{header}\n{'-' * len(header)}")

        for row in subset:
            print(separator.join(row.values()))

        if len(self.data) < n:
            print(f"\nВнимание: в данных только {len(self.data)} строк")

    def info(self) -> None:
        print(f"\nРазмер данных: {len(self.data)}x{len(self.headers)}")

        stats = []
        for col in self.headers:
            non_empty = 0
            types = set()
            for row in self.data:
                value = row[col].strip()
                if value:
                    non_empty += 1
                    try:
                        int(value)
                        types.add(int)
                    except ValueError:
                        try:
                            float(value)
                            types.add(float)
                        except ValueError:
                            types.add(str)

            if len(types) == 0:
                col_type = 'unknown'
            else:
                col_type = next((t.__name__ for t in [int, float] if t in types), 'string')

            stats.append((col, non_empty, col_type))

        print("\nСтатистика по колонкам:")
        for col, count, dtype in stats:
            print(f"{col.ljust(15)}{str(count).ljust(8)}{dtype}")

    def del_nan(self) -> None:
        self.data = [row for row in self.data if all(v.strip() for v in row.values())]

    def make_ds(self) -> None:
        random.shuffle(self.data)
        split_idx = int(0.7 * len(self.data))

        base_dir = "workdata"
        os.makedirs(os.path.join(base_dir, "Learning"), exist_ok=True)
        os.makedirs(os.path.join(base_dir, "Testing"), exist_ok=True)

        def save_subset(subset: List[Dict], path: str) -> None:
            with open(path, 'w', newline='', encoding='utf-8') as f:
                writer = csv.DictWriter(f, fieldnames=self.headers)
                writer.writeheader()
                writer.writerows(subset)

        save_subset(self.data[:split_idx], os.path.join(base_dir, "Learning", "Employees.csv"))
        save_subset(self.data[split_idx:], os.path.join(base_dir, "Testing", "Employees.csv"))

        print(f"\nДанные успешно разделены и сохранены в папку {base_dir}")

reader = CSV("Employees.csv")
reader.show("top", 52, " ")
reader.show("bottom", 0, " ")
reader.info()
reader.del_nan()
reader.make_ds()