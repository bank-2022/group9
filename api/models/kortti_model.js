const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where idKortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.PINkoodi, saltRounds, function(err, hash){
      return db.query(
        'insert into kortti (kortinnumero, PINkoodi, Asiakas_idAsiakas, Tili_idTili) values(?,?,?,?)',
        [kortti.kortinnumero, hash, kortti.Asiakas_idAsiakas, kortti.Tili_idTili],
        callback
      );
    })
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idKortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    bcrypt.hash(kortti.PINkoodi, saltRounds, function(err, hash){
      return db.query(
        'update kortti set kortinnumero=?, PINkoodi=?, Asiakas_idAsiakas=?, Tili_idTili=? where idKortti=?',
        [kortti.kortinnumero, hash, kortti.Asiakas_idAsiakas, kortti.Tili_idTili, id],
        callback
      );
    })
  }
};
module.exports = kortti;