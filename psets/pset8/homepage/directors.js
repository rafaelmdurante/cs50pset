const directors = [
  {
    name: 'Ingmar Bergman',
    birth: '1918',
    country: 'Sweden'
  },
  {
    name: 'Akira Kurosawa',
    birth: '1910',
    country: 'Japan'
  },
  {
    name: 'Christopher Nolan',
    birth: '1970',
    country: 'England'
  },
  {
    name: 'Alfred Hitchcock',
    birth: '1899',
    country: 'England'
  },
  {
    name: 'Stanley Kubrick',
    birth: '1928',
    country: 'The USA'
  },
  {
    name: 'Lars von Trier',
    birth: '1956',
    country: 'Denmark'
  },
  {
    name: 'Walter Salles',
    birth: '1956',
    country: 'Brasil'
  },
  {
    name: 'Quentin Tarantino',
    birth: '1963',
    country: 'The USA'
  }
];

function loadDirectors() {
  let el = document.getElementById('directorsList');

  let counter = 0;

  for (director of directors) {
    let row = `
    <tr>
      <th scope="row">${++counter}</th>
      <td>${director.name}</td>
      <td>${director.birth}</td>
      <td>${director.country}</td>
    </tr>
    `;

    el.innerHTML += row;
  }
}

(function () {
  loadDirectors();
})();
