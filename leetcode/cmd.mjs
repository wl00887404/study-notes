import axios from 'axios';
import { resolve } from 'path';
import { readFileSync, writeFileSync, appendFileSync } from 'fs';
import { exec } from 'child_process';
import chalk from 'chalk';

const scriptPath = process.argv[1];
const action = process.argv[2];
const questionsPath = resolve(scriptPath, `../questions.json`);

const main = async () => {
  if (action === 'update') {
    const { data } = await axios.get('https://leetcode.com/api/problems/all');

    return writeFileSync(questionsPath, JSON.stringify(data.stat_status_pairs));
  }
  if (action === 'add') {
    const questionId = parseInt(process.argv[3]);
    const questions = JSON.parse(
      readFileSync(questionsPath, { encoding: 'utf-8' }),
    );

    const question = questions.find(
      question => question.stat.frontend_question_id === questionId,
    );

    if (!question) return console.error(chalk.red('question not found'));

    const questionTitle = question.stat.question__title
      .replace(/[-\s(),]/g, '_')
      .replace(/_+/g, '_')
      .replace(/_$/g, '')
      .toLowerCase();

    const filePath = resolve(
      scriptPath,
      `../${questionId}_${questionTitle}.cxx`,
    );

    appendFileSync(filePath, '');

    return exec(`code ${filePath}`)
  }

  console.error(chalk.red('command not found'));
};

main();
