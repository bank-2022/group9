const db = require('../database');

const login={
  checkPINkoodi: function(kortinnumero, callback) {
      return db.query('SELECT PINkoodi FROM kortti WHERE kortinnumero = ?',[kortinnumero], callback); 
    }
};
          
module.exports = login;