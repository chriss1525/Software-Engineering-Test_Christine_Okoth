import sqlite3
import os

def run_test():
    conn = sqlite3.connect(':memory:')
    cursor = conn.cursor()

    # quick table + data so I can test the query
    cursor.execute("""
        CREATE TABLE STUDENT (
            ID INTEGER PRIMARY KEY,
            NAME TEXT,
            SCORE REAL
        )
    """)

    data = [
        (1, 'Bob', 50.0), (2, 'John', 65.5), (3, 'Harry', 45.0),
        (4, 'Dick', 85.0), (5, 'Dev', 25.0), (6, 'Sid', 98.0),
        (7, 'Tom', 90.0), (8, 'Julia', 70.5), (9, 'Erica', 81.0),
        (10, 'Jerry', 85.0)
    ]

    cursor.executemany(
        'INSERT INTO STUDENT (ID, NAME, SCORE) VALUES (?, ?, ?)',
        data
    )

    # read my query from file
    sql_path = os.path.join(os.path.dirname(__file__), '..', 'top_students.sql')
    with open(sql_path) as f:
        query = f.read()

    # run it and just print results
    print("ID | NAME")
    print("----------")

    for row in cursor.execute(query):
        print(f"{row[0]} | {row[1]}")

if __name__ == '__main__':
    run_test()