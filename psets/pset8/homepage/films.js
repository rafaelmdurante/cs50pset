const films = [
  {
    title: 'The Seventh Seal',
    url: 'https://www.imdb.com/title/tt0050976/',
    poster: 'https://m.media-amazon.com/images/M/MV5BM2I1ZWU4YjMtYzU0My00YmMzLWFmNTAtZDJhZGYwMmI3YWQ5XkEyXkFqcGdeQXVyNjU0OTQ0OTY@._V1_UX182_CR0,0,182,268_AL_.jpg',
    director: 'Ingmar Bergman',
    year: '1957'
  },
  {
    title: 'Dreams',
    url: 'https://www.imdb.com/title/tt0100998/',
    poster: 'https://m.media-amazon.com/images/M/MV5BNDBkODdjMzEtNTY1NC00ZWQ5LTk3NDUtY2IwMTk5MzhmNTUwXkEyXkFqcGdeQXVyNjc1NTYyMjg@._V1_UY268_CR4,0,182,268_AL_.jpg',
    director: 'Akira Kurosawa',
    year: '1990'
  },
  {
    title: 'Interstellar',
    url: 'https://www.imdb.com/title/tt0816692/',
    poster: 'https://m.media-amazon.com/images/M/MV5BZjdkOTU3MDktN2IxOS00OGEyLWFmMjktY2FiMmZkNWIyODZiXkEyXkFqcGdeQXVyMTMxODk2OTU@._V1_UX182_CR0,0,182,268_AL_.jpg',
    director: 'Christopher Nolan',
    year: '2014'
  },
  {
    title: 'Rear Window',
    url: 'https://www.imdb.com/title/tt0047396/',
    poster: 'https://m.media-amazon.com/images/M/MV5BYjJkZGVjMDMtMzNmZS00NDQ3LWE1YWEtMDlmYjExMTA4MGFkXkEyXkFqcGdeQXVyODY0NzcxNw@@._V1_UX182_CR0,0,182,268_AL_.jpg',
    director: 'Alfred Hitchcock',
    year: '1954'
  },
  {
    title: '2001: A Space Odyssey',
    url: 'https://www.imdb.com/title/tt0062622/',
    poster: 'https://m.media-amazon.com/images/M/MV5BMmNlYzRiNDctZWNhMi00MzI4LThkZTctMTUzMmZkMmFmNThmXkEyXkFqcGdeQXVyNzkwMjQ5NzM@._V1_UX182_CR0,0,182,268_AL_.jpg',
    director: 'Stanley Kubrick',
    year: '1968'
  },
  {
    title: 'Antichrist',
    url: 'https://www.imdb.com/title/tt0870984/',
    poster: 'https://m.media-amazon.com/images/M/MV5BMjE3MjQ2ODc1N15BMl5BanBnXkFtZTcwNjYyMzI5Mg@@._V1_UY268_CR6,0,182,268_AL_.jpg',
    director: 'Lars von Trier',
    year: '2009'
  },
  {
    title: 'Central do Brasil',
    url: 'https://www.imdb.com/title/tt0140888/',
    poster: 'https://m.media-amazon.com/images/M/MV5BMjE3ZDA5ZmUtYTk1ZS00NmZmLWJhNTItYjIwZjUwN2RjNzIyXkEyXkFqcGdeQXVyMTkzODUwNzk@._V1_UX182_CR0,0,182,268_AL_.jpg',
    director: 'Walter Salles',
    year: '1998'
  },
  {
    title: 'Django Unchained',
    url: 'https://www.imdb.com/title/tt1853728/',
    poster: 'https://m.media-amazon.com/images/M/MV5BMjIyNTQ5NjQ1OV5BMl5BanBnXkFtZTcwODg1MDU4OA@@._V1_UX182_CR0,0,182,268_AL_.jpg',
    director: 'Quentin Tarantino',
    year: '2012'
  }
];

function loadFilms() {
  let el = document.getElementById('filmList');

  for (film of films) {
    let cardContent = `
      <li class="card">
        <img src="${film.poster}" alt="" class="card-img-top">
        <div class="card-body">
          <h5 class="card-title">${film.title}</h5>
          <p class="card-text">${film.director}, ${film.year}</p>
          <a href="${film.url}" class="btn btn-sm btn-warning" target="_blank">IMDB</a>
        </div>
      </li>
    `;

    el.innerHTML += cardContent;
  }
}

(function () {
  loadFilms();
})();