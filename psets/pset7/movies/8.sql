-- list the names of all people who starred in Toy Story.
    -- a single column for the name of each person.
    -- assume that there is only one movie with the title Toy Story.
-- 4 rows
SELECT p.name FROM people p
  JOIN stars s ON p.id = s.person_id
  JOIN movies m ON s.movie_id = m.id
WHERE m.title = 'Toy Story';
