-- list the titles of all movies in which
    -- both Johnny Depp and Helena Bonham Carter starred.
-- a single column for the title of each movie.
-- assume that there is only one Johnny Depp.
-- assume that there is only one Helena Bonham Carter.
-- 6 rows.
-- SELECT title FROM movies m
--     JOIN stars s ON m.id = s.movie_id
--     JOIN people p ON s.person_id = p.id
-- WHERE p.name = 'Johnny Depp'
-- INTERSECT
-- SELECT title FROM movies m
--     JOIN stars s ON m.id = s.movie_id
--     JOIN people p ON s.person_id = p.id
-- WHERE p.name = 'Helena Bonham Carter'

SELECT title FROM movies m
    JOIN stars s ON m.id = s.movie_id
    JOIN people p ON s.person_id = p.id
WHERE p.name = 'Johnny Depp'
AND movie_id IN 
(
    SELECT movie_id FROM stars s
    JOIN people p ON s.person_id = p.id
    WHERE p.name = 'Helena Bonham Carter'
)

