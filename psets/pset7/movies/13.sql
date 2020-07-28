-- list the names of all people who starred in a movie
    -- in which Kevin Bacon also starred.
-- single column for the name of each person.
-- There may be multiple people named Kevin Bacon in the database.
    -- Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list.
-- 176 rows

-- SELECT p.name FROM people p
--     JOIN stars s ON p.id = s.person_id
--     JOIN movies m ON s.movie_id = m.id
-- WHERE p.name = 'Kevin Bacon' AND p.birth = 1958
-- GROUP BY p.name, p.id;

SELECT p.name FROM people p
    JOIN stars s ON s.person_id = p.id
    JOIN movies m ON m.id = s.movie_id
WHERE p.name IS NOT 'Kevin Bacon'
AND m.id IN (
    SELECT m.id FROM movies m
        JOIN stars s ON s.movie_id = m.id
        JOIN people p ON p.id = s.person_id
    WHERE p.name = 'Kevin Bacon' AND p.birth = 1958
)
GROUP BY p.id;
