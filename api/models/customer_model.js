const db = require('../database');
const customer = {
  getAll: function(callback) {
    return db.query('select * from customer order by id_customer desc', callback);
  },
  getById: function(id_customer, callback) {
    return db.query('select * from customer where id_customer=?', [id_customer], callback);
  },
  add: function(customer, callback) {
    console.log(customer);
    return db.query(
      'insert into customer (fname, lname, address, telephone) values(?,?,?,?)',
      [customer.fname, customer.lname, customer.address, customer.telephone],
      callback
    );
  },
  delete: function(id_customer, callback) {
    return db.query('delete from customer where id_customer=?', [id_customer], callback);
  },
  update: function(id_customer, customer, callback) {
    return db.query(
      'update customer set fname=?, lname=?, address=?, telephone=? where id_customer=?',
      [customer.fname, customer.lname, customer.address, customer.telephone, id_customer],
      callback
    );
  }
};
module.exports = customer;