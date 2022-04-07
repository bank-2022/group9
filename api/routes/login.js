const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');
const kortti = require('../models/kortti_model');

router.post('/', 
  function(request, response) {
    if(request.body.kortinnumero && request.body.PINkoodi){
      const kortinnumero = request.body.kortinnumero;
      const PINkoodi = request.body.PINkoodi;
        login.checkPINkoodi(kortinnumero, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(PINkoodi,dbResult[0].PINkoodi, function(err,compareResult) {
                if(compareResult) {
                  console.log("succes");
                  const token = generateAccessToken({ kortinnumero: kortinnumero });
                  response.send(token);
                }
                else {
                    console.log("wrong PINkoodi");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("kortinnumero or PINkoodi missing");
      response.send(false);
    }
  }
);

function generateAccessToken(kortinnumero) {
  dotenv.config();
  return jwt.sign(kortinnumero, process.env.MY_TOKEN, { expiresIn: '1800s' });
}

module.exports=router;