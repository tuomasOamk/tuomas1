var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

const cardRouter = require('./routes/card');
const customerRouter = require('./routes/customer');
const accountRouter = require('./routes/account');
const transactionRouter = require('./routes/transaction')
const helmet = require('helmet');
const cors = require('cors');



var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use(helmet());
app.use(cors());
app.use('/card', cardRouter);
app.use('/customer', customerRouter);
app.use('/account', accountRouter);
app.use('/transaction', transactionRouter);


module.exports = app;
