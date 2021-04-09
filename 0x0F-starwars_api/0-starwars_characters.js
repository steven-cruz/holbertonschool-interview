#!/usr/bin/node

const request = require('request');
const filmsNum = process.argv[2] + '/';
const urlFilms = 'https://swapi-api.hbtn.io/api/films/';

request(urlFilms + filmsNum, async function (err, res, body) {
  if (err) return console.error(err);

  const urlList = JSON.parse(body).characters;

  for (const url of urlList) {
    await new Promise(function (resolve, reject) {
      request(url, function (err, res, body) {
        if (err) return console.error(err);
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
