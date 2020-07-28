-- list the titles of the five highest rated movies (in order)
    -- that Chadwick Boseman starred in, starting with the highest rated.
    -- a single column for the title of each movie.
    -- assume that there is only one Chadwick Boseman.
-- 5 rows
SELECT title FROM movies m
    JOIN stars s ON m.id = s.movie_id
    JOIN people p ON s.person_id = p.id
    JOIN ratings r ON r.movie_id = m.id
WHERE p.name = 'Chadwick Boseman'
ORDER BY r.rating DESC
LIMIT 5;
