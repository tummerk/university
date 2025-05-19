import csv
import os
import random
import numpy as np



def task1():
    # Создание файла с матрицей
    with open('matrix.txt', 'w') as f:
        f.write("3,4,17,-3\n5,11,-1,6\n0,2,-5,8")

    # Чтение и обработка данных
    matrix = []
    with open('matrix.txt', 'r') as f:
        for line in f:
            row = list(map(int, line.strip().split(',')))
            matrix.append(row)

    # Вычисления
    flat_list = [num for row in matrix for num in row]
    return {
        "sum": sum(flat_list),
        "max": max(flat_list),
        "min": min(flat_list)
    }



def task2(x):
    values, counts = [], []
    current, count = x[0], 1
    for num in x[1:]:
        if num == current:
            count += 1
        else:
            values.append(current)
            counts.append(count)
            current, count = num, 1
    values.append(current)
    counts.append(count)
    return (np.array(values), np.array(counts))



def task3():
    np.random.seed(42)
    arr = np.random.normal(size=(10, 4))
    return {
        "first_5_rows": arr[:5],
        "stats": {
            "min": arr.min(),
            "max": arr.max(),
            "mean": arr.mean(),
            "std": arr.std()
        }
    }


def task4(x):
    zero_positions = np.where(x[:-1] == 0)[0]
    return x[zero_positions + 1].max() if zero_positions.size > 0 else None


def task5(X, m, C):
    diff = X - m
    inv_C = np.linalg.inv(C)
    exponent = -0.5 * np.sum(diff @ inv_C * diff, axis=1)
    return -0.5 * (len(m) * np.log(2 * np.pi) + np.log(np.linalg.det(C))) + exponent



def task6():
    a = np.arange(16).reshape(4, 4)
    a[[1, 3]] = a[[3, 1]]
    return a


def task7():
    url = 'https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data'
    iris = np.genfromtxt(url, delimiter=',', dtype='object')
    species = iris[:, -1]
    unique, counts = np.unique(species, return_counts=True)
    return dict(zip(unique, counts))



def task8(x):
    return np.nonzero(x)[0]

t1 = task1()
print(f"Сумма: {t1['sum']}, Максимум: {t1['max']}, Минимум: {t1['min']}")

x = np.array([2, 2, 2, 3, 3, 3, 5])
v, c = task2(x)
print(f"Значения: {v}, Повторы: {c}")

t3 = task3()
print(t3["stats"])


x = np.array([6, 2, 0, 3, 0, 0, 5, 7, 0])
print("Максимум после нулей:", task4(x))

X = np.random.randn(100, 3)
m = np.zeros(3)
C = np.eye(3)
print(task5(X, m, C))

print(task6())

print(task7())

x = np.array([0, 1, 2, 0, 0, 4, 0, 6, 9])
print(task8(x))