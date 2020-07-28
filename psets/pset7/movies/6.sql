SELECT ROUND(AVG(r.rating), 2) AS average FROM ratings r
    JOIN movies m ON r.movie_id = m.id
    WHERE m.year = 2012;
