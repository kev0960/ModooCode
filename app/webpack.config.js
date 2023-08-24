const webpack = require('webpack');
const path = require('path');

module.exports = {
  entry: './src/index.ts',
  output: {
    path: path.resolve(__dirname, '../static/dist'),
    filename: 'new_page.bundle.js'
  },
  // devtool: 'inline-source-map',
  mode: 'production',
  module:
      {rules: [{test: /\.tsx?$/, use: 'ts-loader', exclude: /node_modules/}]},
  resolve: {extensions: ['.tsx', '.ts', '.js']},
}