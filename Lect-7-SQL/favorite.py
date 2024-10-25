from cs50 import SQL

db = SQL("sqlite:///favorite.db")

favorite = input("Favorite: ")

db.execute("SELECT COUNT(*) AS n FROM favorite WHERE problem = ?", favorite)
row = rows[0]

print(row['n'])
