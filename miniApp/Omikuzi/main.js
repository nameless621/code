'use strict'

{
  const btn = document.getElementById('btn');
  const result = document.getElementById('result');

  btn.addEventListener('click', () => {
    const results = [
      '大大吉',
      '大吉',
      '向大吉',
      '末大吉',
      '吉凶末分末大吉',
      '吉',
      '中吉',
      '小吉',
      '後吉',
      '末吉',
      '吉凶不分末吉',
      '吉凶相交末吉',
      '吉凶相半',
      '吉凶相央',
      '小凶後吉',
      '凶後吉',
      '凶後大吉',
    ]
    const idx = Math.floor(Math.random() * results.length);
    result.textContent = results[idx];
  });
}