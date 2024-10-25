-- write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.

SELECT movies.title FROM movies JOIN stars On stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE people.name = "Johnny Depp"
INTERSECT
SELECT movies.title FROM movies JOIN stars
ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE people.name = 'Helena Bonham Carter';


