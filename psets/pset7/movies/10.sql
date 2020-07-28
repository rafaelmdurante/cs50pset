-- list the names of all people who have directed a movie
    -- that received a rating of at least 9.0.
-- a single column for the name of each person.
-- 1,841 rows.
SELECT name FROM people p
    JOIN directors d ON p.id = d.person_id
    JOIN movies m ON d.movie_id = m.id
    JOIN ratings r ON m.id = r.movie_id
WHERE r.rating >= 9.0
GROUP BY p.name;
